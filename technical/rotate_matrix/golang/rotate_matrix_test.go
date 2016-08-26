package rotate_matrix

import "testing"

func TestSingle(t *testing.T) {
	row := []int{1}
	matrix := make([][]int, 0)
	matrix = append(matrix, row)
	rotate(matrix)
	if matrix[0][0] != 1 {
		t.Fail()
	}
}

func TestDouble(t *testing.T) {
	row0 := []int{0, 1}
	row1 := []int{2, 3}
	matrix := make([][]int, 0)
	matrix = append(matrix, row0)
	matrix = append(matrix, row1)
	rotate(matrix)
	if matrix[0][0] != 2 || matrix[0][1] != 0 || matrix[1][0] != 3 || matrix[1][1] != 1 {
		t.Fail()
	}
}

func TestTriple(t *testing.T) {
	row0 := []int{0, 1, 2}
	row1 := []int{3, 4, 5}
	row2 := []int{6, 7, 8}
	matrix := make([][]int, 0)
	matrix = append(matrix, row0)
	matrix = append(matrix, row1)
	matrix = append(matrix, row2)
	rotate(matrix)
	if matrix[0][0] != 6 || matrix[0][1] != 3 || matrix[0][2] != 0 {
		t.Fail()
	}
	if matrix[1][0] != 7 || matrix[1][1] != 4 || matrix[1][2] != 1 {
		t.Fail()
	}
	if matrix[2][0] != 8 || matrix[2][1] != 5 || matrix[2][2] != 2 {
		t.Fail()
	}
}
