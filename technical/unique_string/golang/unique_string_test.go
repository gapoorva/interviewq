package unique_string

import "testing"

func TestUniqueString1(t *testing.T) {
	s := "astring"
	empty := ""
	dups := "heywhatsupdoe"
	specialchars := "(^)@)!(@*@&!%#^Y!"

	if !IsUnique1(s) || !IsUnique1(empty) || IsUnique1(dups) || IsUnique1(specialchars) {
		t.Fail()
	}
}

func TestUniqueString2(t *testing.T) {
	s := "astring"
	empty := ""
	dups := "heywhatsupdoe"
	specialchars := "(^)@)!(@*@&!%#^Y!"

	if !IsUnique2(s) || !IsUnique2(empty) || IsUnique2(dups) || IsUnique2(specialchars) {
		t.Fail()
	}
}

func TestUniqueString3(t *testing.T) {
	s := "astring"
	empty := ""
	dups := "heywhatsupdoe"
	specialchars := "(^)@)!(@*@&!%#^Y!"

	if !IsUnique3(s) || !IsUnique3(empty) || IsUnique3(dups) || IsUnique3(specialchars) {
		t.Fail()
	}
}
