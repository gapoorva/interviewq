package anagrams

import "testing"

func TestAreAnagrams1(t *testing.T) {
	emptyA := []byte("")
	emptyB := []byte("")
	uneqA := []byte("length")
	uneqB := []byte("lengths")
	reflexiveA := []byte("property")
	reflexiveB := []byte("property")
	googleA := []byte("cinema")
	googleB := []byte("iceman")
	extraA := []byte("cinema")
	extraB := []byte("icemam")
	differentA := []byte("cinema")
	differentB := []byte("icemat")

	if !AreAnagrams1(emptyA, emptyB) {
		t.Fail()
	}
	if AreAnagrams1(uneqA, uneqB) {
		t.Fail()
	}
	if !AreAnagrams1(reflexiveA, reflexiveB) {
		t.Fail()
	}
	if !AreAnagrams1(googleA, googleB) {
		t.Fail()
	}
	if AreAnagrams1(extraA, extraB) {
		t.Fail()
	}
	if AreAnagrams1(differentA, differentB) {
		t.Fail()
	}
}

func TestAreAnagrams2(t *testing.T) {
	emptyA := []byte("")
	emptyB := []byte("")
	uneqA := []byte("length")
	uneqB := []byte("lengths")
	reflexiveA := []byte("property")
	reflexiveB := []byte("property")
	googleA := []byte("cinema")
	googleB := []byte("iceman")
	extraA := []byte("cinema")
	extraB := []byte("icemam")
	differentA := []byte("cinema")
	differentB := []byte("icemat")

	if !AreAnagrams2(emptyA, emptyB) {
		t.Error()
	}
	if AreAnagrams2(uneqA, uneqB) {
		t.Error()
	}
	if !AreAnagrams2(reflexiveA, reflexiveB) {
		t.Error()
	}
	if !AreAnagrams2(googleA, googleB) {
		t.Error()
	}
	if AreAnagrams2(extraA, extraB) {
		t.Error()
	}
	if AreAnagrams2(differentA, differentB) {
		t.Error()
	}
}
