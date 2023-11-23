package go_1410

type wordMap map[string]byte

func getWord() wordMap {
	word := make(map[string]byte)
	patterns := []string{"&quot;", "&apos;", "&amp;", "&gt;", "&lt;", "&frasl;"}
	after := []byte{'"', '\'', '&', '>', '<', '/'}
	for i, pattern := range patterns {
		word[pattern] = after[i]
	}
	return word
}
func entityParser(text string) string {
	word := getWord()
	var ans = make([]byte, 0)

	l := len(text)
	for i := 0; i < l; {
		c := text[i]
		ok := false
		if c == '&' {
			for key, value := range word {
				if i+len(key) <= l && text[i:i+len(key)] == key {
					// 匹配成功
					ans = append(ans, value)
					i += len(key)
					ok = true
					break
				}
			}
		}
		if !ok {
			// 匹配失败
			ans = append(ans, c)
			i += 1
		}
	}
	return string(ans)
}
