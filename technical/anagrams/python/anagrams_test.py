from anagrams import anagram

emptyA = ''
emptyB = ''
uneqA = 'length'
uneqB = 'lengths'
reflexiveA = 'property'
reflexiveB = 'property'
googleA = 'cinema'
googleB = 'iceman'
extraA = 'cinema'
extraB = 'icemam'
differentA = 'cinema'
differentB = 'icemat'


print 'two empty strings: ' + str(anagram(emptyA, emptyB))
print 'two unique strings: ' + str(anagram(uneqA, uneqB))
print 'the same string: ' + str(anagram(reflexiveA, reflexiveB))
print 'anagram strings: ' + str(anagram(googleA, googleB))
print 'one letter different strings: ' + str(anagram(extraA, extraB))
print 'totally different strings: ' + str(anagram(differentA, differentB))





