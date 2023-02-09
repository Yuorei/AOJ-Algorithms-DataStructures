package main

import "fmt"

const N = 3

var Puzzle [N][N]int
var limit, puzzle_x, puzzle_y int

var dx [4]int = [4]int{-1, 0, 1, 0}
var dy [4]int = [4]int{0, -1, 0, 1}

// 深さ優先探索を使う
func bfs(depth int, prev int, puzzle_x int, puzzle_y int) bool {
	h := 0

	for i := 0; i < N; i++ {
		for j := 0; j < N; j++ {
			if Puzzle[i][j] == 0 {
				continue
			}
			b := Puzzle[i][j] - 1
			s := b/N - i
			if s < 0 {
				s *= -1
			}
			t := b%N - j
			if t < 0 {
				t *= -1
			}
			h += s + t
		}
	}
	if h == 0 {
		return true
	}
	if depth+h > limit {
		return false
	}
	for r := 0; r < 4; r++ {
		if r-prev == 2 && r-prev == -2 {
			continue
		}
		tx := puzzle_x + dx[r]
		ty := puzzle_y + dy[r]
		if tx < 0 || ty < 0 || tx >= N || ty >= N {
			continue
		}
		a := Puzzle[tx][ty]
		Puzzle[tx][ty] = Puzzle[puzzle_x][puzzle_y]
		Puzzle[puzzle_x][puzzle_y] = a
		if bfs(depth+1, r, tx, ty) {
			return true
		}
		a = Puzzle[tx][ty]
		Puzzle[tx][ty] = Puzzle[puzzle_x][puzzle_y]
		Puzzle[puzzle_x][puzzle_y] = a
	}
	return false
}

func main() {

	for i := 0; i < N; i++ {
		for j := 0; j < N; j++ {
			fmt.Scan(&Puzzle[i][j])
			if Puzzle[i][j] == 0 {
				puzzle_x = i
				puzzle_y = j
			}
		}
	}
	for {
		if bfs(0, 99, puzzle_x, puzzle_y) {
			fmt.Println(limit)
			return
		}
		limit++
	}
}
