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
