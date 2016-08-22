package reverse_c_style_string

func Reverse(b []byte) []byte {
	l := len(b)
	if l == 0 {
		return []byte{}
	}
	strlen := 0
	for int(b[strlen]) != 0 {
		strlen++
	}
	for i := 0; i < strlen/2; i++ {
		tmp := b[i]
		b[i] = b[strlen-i-1]
		b[strlen-i-1] = tmp
	}
	return b
}
