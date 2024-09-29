package main


import "fmt"

func toString(num int) string {
	return fmt.Sprintf("%v", num);
}

func isPalindrome(x int) bool {
	old_str := toString(x);
	// Convert string to a slice of runes to handle multibyte characters (like Unicode)
	runes := []rune(old_str)

	// Create a new slice to store the reversed characters
	new_str := make([]rune, len(runes))
	j := 0;
	for i := len(runes) - 1; i >= 0; i-- {
		new_str[j] = runes[i];
		j++;
	}
	// fmt.Printf(("Old String: %s and New String: %s"), old_str, string(new_str))

	if(old_str == string(new_str)) {
		return true;
	}
	return false;
}

func main() {
	fmt.Println(isPalindrome(1122))
}