import ( 
    "fmt"
    "math"
) 

func asteroidCollision(asteroids []int) []int {
    stack := []int{};
    i := 0;
    for i < len(asteroids){
        if len(stack) == 0 {
            stack = append(stack, asteroids[i]);
            i += 1;
            continue;
        }
        
        if stack[len(stack) - 1] * asteroids[i] > 0 {
            stack = append(stack, asteroids[i]);
        } else {
            if stack[len(stack) - 1] < 0 {
                stack = append(stack, asteroids[i]);
                i += 1
                continue
            }
            if math.Abs(float64(stack[len(stack) - 1])) < math.Abs(float64(asteroids[i])) && len(stack) > 0 {
                stack = stack[:len(stack) - 1]; // pop the stacks
                continue;
            } else if len(stack) < 0 {
                stack = append(stack, asteroids[i]);
            } else if math.Abs(float64(stack[len(stack) - 1])) == math.Abs(float64(asteroids[i])) {
                stack = stack[:len(stack) - 1]; // pop the stacks
            }
        }
        // fmt.Println(stack)
        i += 1;
    }
    return stack;
}