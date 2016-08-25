package anagrams

import "sort"

// uses a linear time solution
func AreAnagrams1(a []byte, b []byte) bool {
	if len(a) != len(b) {
		return false
	}
	counts := make(map[byte]int)
	for _, c := range a {
		if _, ok := counts[c]; ok {
			counts[c] = counts[c] + 1
		} else {
			counts[c] = 1
		}
	}
	for _, c := range b {
		if _, ok := counts[c]; !ok {
			return false
		} else {
			counts[c] = counts[c] - 1
			if counts[c] < 0 {
				return false
			}
		}
	}
	return true
}

type sortSlice []byte

func (s sortSlice) Len() int {
	return len(s)
}

func (s sortSlice) Swap(i, j int) {
	tmp := s[i]
	s[i] = s[j]
	s[j] = tmp
}

func (s sortSlice) Less(i, j int) bool {
	return s[i] < s[j]
}

// uses constant space
func AreAnagrams2(a []byte, b []byte) bool {
	if len(a) != len(b) {
		return false
	}
	sort.Sort(sortSlice(a))
	sort.Sort(sortSlice(b))
	for i := range a {
		if a[i] != b[i] {
			return false
		}
	}
	return true
}

func anagramDistance(x []byte, y []byte) int {
	// assumes x and y are anagrams!!
	// base case: length 1
	dist := 0
	for i, dest := range y {
		if x[i] != dest {
			j := i + 1
			for j < len(x) && x[j] == dest && y[j] != dest {
				j++
			}
			if j < len(x) {
				tmp := x[j]
				x[j] = x[i]
				x[i] = tmp
				dist++
			}
		}
	}
	return dist
}

/*
	Calculates the "distance" between two strings measured in the number of the following operations it takes to transform x to y:
	* Swap two characters at positions i, j in an N length string where i <= j < N (swap)
	* Append a character to the end of the string (push)
	* Remove a character from the end of the string (pop)
*/
func Distance(x []byte, y []byte) int {
	if len(x) == 0 {
		return len(y) // |y| pushes
	}
	if len(y) == 0 {
		return len(x) // |x| pops
	}
	// There are 3 significant cases here:
	/*
		(1) |x| == |y|, |x| = N
		(2) |x| < |y|, |x| = N, |y| = M
		(3) |x| > |y|, |x| = N, |y| = M

		In (1), at most N replacement operations are need to transform x to an anagram of y
		In (2), M-N additions followed by at most N replacements are needed to transform x to an anagram of y
		In (3), N-M deletions followed by at most N replacements are needed to transform x to an anagram of y

		Where replacement is done by:
			push r
			swap r, i
			pop
		additions are done by:
			push r
		and deletions are done by:
			swap i, end
			pop

		When x and y are anagrams, the remaining distance is the number of swaps needed to transform x into y. Call this amount S

		Then, the distance between the two strings is:
		D = 3 * replacements + 2 * deletions + additions + S
	*/

	countsY := make(map[byte]int)
	total := 0
	swaps := 0
	// get a set of counts of bytes by byte value for y
	for _, b := range y {
		if _, ok := countsY[b]; ok {
			countsY[b] = countsY[b] + 1
		}
		countsY[b] = 1
	}
	// find indexes of characters in x that
	// 	 (a) aren't in y
	//   (b) are present in a greater frequency than in y
	// so that we can replace them
	replaceInXIndexes := make([]int, 0)
	for i, b := range x {
		if count, ok := countsY[b]; ok && count > 0 {
			countsY[b] = countsY[b] - 1
		} else {
			replaceInXIndexes = append(replaceInXIndexes, i)
		}
	}
	// 2 cases
	if len(x) < len(y) {
		// must add characters. Best characters to add
		// are those that are in Y but not in x
		additions := len(y) - len(x)
		total = total + additions
		for k, v := range countsY {
			if additions == 0 {
				break
			}
			if v == 0 {
				continue
			}
			x = append(x, k)
			countsY[k] = v - 1
			additions--
		}
	} else if len(x) > len(y) {
		// must remove characters. Best characters to remove
		// are those that are marked for replacement
		deletions := len(x) - len(y)
		total = total + deletions*2
		for deletions != 0 {
			iToDelete := replaceInXIndexes[len(replaceInXIndexes)-1]
			// swap to len(y) + deletions - 1
			tmp := x[iToDelete]
			x[iToDelete] = x[len(y)+deletions-1]
			x[len(y)+deletions-1] = tmp
			deletions--
			replaceInXIndexes = replaceInXIndexes[:len(replaceInXIndexes)-1] // chop off
		}
		// "deletions" amount of garbage data is at the end of x now
		x = x[:len(x)-deletions]
	}

	// Now |x| == |y|, |x| == N (case #1) is true
	replacements := len(replaceInXIndexes)
	total = total + replacements*3
	for k, v := range countsY {
		if v == 0 {
			continue
		}
		if replacements == 0 {
			break // but this should never happen
		}
		for v != 0 {
			x = append(x, k)
			countsY[k] = v - 1
			tmp := x[replaceInXIndexes[replacements-1]]
			x[replaceInXIndexes[replacements-1]] = x[len(x)-1]
			x[len(x)-1] = tmp
			x = x[:len(x)-1]
			replacements--
		}
	}

	// Now x and y are anagrams. The final step is to compute the number of differences
	// Let y be the destination and x be the source
	return total + anagramDistance(x, y)
}
