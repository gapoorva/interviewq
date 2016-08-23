package rm_duplicates

func RemoveDuplicates(s []byte) []byte {
	// O(N^2) solution
	// Assumes strings are null terminated (or that the null byte is not part of a printable string)
	if len(s) <= 1 {
		return s
	}
	// pass 1 - mark duplicates
	duplicates := 0
	for i, a := range s[:len(s)-1] {
		for j, b := range s[i+1:] {
			if a == b && a != byte(0) {
				s[j+i+1] = byte(0) // marking j as duplicate
				duplicates++
			}
		}
	}

	seeker := 0
	for inserter := 0; inserter < len(s)-duplicates; inserter++ {
		for int(s[seeker]) == 0 {
			seeker++
		}
		s[inserter] = s[seeker]
		seeker++
	}
	return s[:len(s)-duplicates]
}
