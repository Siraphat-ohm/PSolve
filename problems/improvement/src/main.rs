use std::io::{self, Read};

macro_rules! read {
    ($it:expr, $t:ty) => {
        $it.next().unwrap().parse::<$t>().unwrap()
    };
}

fn solve(i: usize, n: usize, scores: &[i32]) -> (i32, i32, i32) {
    if i == n - 1 {
        return (0, 0, scores[i]);
    }

    let (mut count_3x, mut count_2x, future_max) = solve(i + 1, n, scores);

    if future_max >= 3 * scores[i] {
        count_3x += 1;
    } else if future_max >= 2 * scores[i] {
        count_2x += 1;
    }

    (count_3x, count_2x, std::cmp::max(scores[i], future_max))
}

fn main() {
    let mut buff = String::new();
    io::stdin().read_to_string(&mut buff).unwrap();

    let mut it = buff.split_whitespace();

    let n = read!(it, usize);

    let scores: Vec<i32> = (0..n).map(|_| read!(it, i32)).collect();

    let (a, b, _) = solve(0, n, &scores);

    println!("{} {}", a, b);
}
