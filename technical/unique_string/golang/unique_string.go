package unique_string

import "sort"

func IsUnique1(s string) bool {
	chars := make(map[rune]bool)
	for _, b := range s {
		if _, ok := chars[b]; ok {
			return false
		}
		chars[b] = true
	}
	return true
}

func IsUnique2(s string) bool {
	for i, a := range s {
		for j, b := range s {
			if i != j && a == b {
				return false
			}
		}
	}
	return true
}

type sortedRunes []rune

func (s sortedRunes) Len() int {
	return len(s)
}

func (s sortedRunes) Less(i, j int) bool {
	return s[i] < s[j]
}

func (s sortedRunes) Swap(i, j int) {
	tmp := s[i]
	s[i] = s[j]
	s[j] = tmp
}

func IsUnique3(s string) bool {
	r := []rune(s) // certain characters in go can be multi-byte, but will be single rune
	sort.Sort(sortedRunes(r))
	for i := 0; i < len(r)-1; i++ {
		if r[i] == r[i+1] {
			return false
		}
	}
	return true
}
