package rotate_matrix

func rotate(matrix [][]int) {
	if len(matrix) < 2 {
		return
	}
	/*
	   Q1:
	   [i, j]     -> [?, ?]
	   [0, 0]     -> [0, N-1]
	   [0, 1]     -> [1, N-1]
	   [1, 0]     -> [0, N-2]
	   [i->j ,j->(N-1-i)]

	   Q2:
	   [i, j] -> [?, ?]
	   [0, n-1] -> [n-1, n-1]
	   [1, n-1] -> [n-1, n-2]
	   [0, n-2] -> [n-2, n-1]
	   [i->j, j->(n-1-i)]

	   Q3:
	   [i, j] -> [?, ?]
	   [N-1, N-1] -> [N-1, 0]

	   PATTERN IS: [i = j, j = N - 1 - i]
	*/
	N := len(matrix)
	odd := N % 2
	for i := 0; i < N/2+odd; i++ {
		for j := 0; j < N/2; j++ {
			// math to figure out these indexes using the above pattern
			tmp := matrix[i][j]
			matrix[i][j] = matrix[N-1-j][i]
			matrix[N-1-j][i] = matrix[N-1-i][N-1-j]
			matrix[N-1-i][N-1-j] = matrix[j][N-1-i]
			matrix[j][N-1-i] = tmp
		}
	}
	return
}
