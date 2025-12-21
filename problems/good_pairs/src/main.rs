use std::io::{self, Read};

macro_rules! read {
    ($it:expr, $t:ty) => {
        $it.next().unwrap().parse::<$t>().unwrap()
    };
}

fn solve(p: &[i32], n: usize, s: i32, t: i32) -> u32 {
    if n < 2 {
        return 0;
    }
    let last_idx = n - 1;
    let pj = p[last_idx];
    let min_pi = (s - pj).max(pj - t);

    let count = last_idx - p[..last_idx].partition_point(|&pi| pi < min_pi);

    (count as u32) + solve(p, n - 1, s, t)
}

fn main() {
    let mut buff = String::new();
    io::stdin().read_to_string(&mut buff).unwrap();

    let mut it = buff.split_whitespace();

    let n = read!(it, usize);
    let s = read!(it, i32);
    let t = read!(it, i32);

    let p: Vec<i32> = (0..n).map(|_| read!(it, i32)).collect();

    println!("{}", solve(&p, n, s, t));
}
