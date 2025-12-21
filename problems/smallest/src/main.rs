use std::io::{self, Read};

macro_rules! read {
    ($it:expr, $t:ty) => {
        $it.next().unwrap().parse::<$t>().unwrap()
    };
}

fn build_prefix(i: usize, n: usize, current_min: u32, h: &[u32], p_min: &mut Vec<u32>) {
    if i == n {
        return;
    }

    let new_min = std::cmp::min(current_min, h[i]);
    p_min.push(new_min);

    build_prefix(i + 1, n, new_min, h, p_min);
}

fn find_furthest(low: u32, high: u32, k: u32, p_min: &[u32]) -> u32 {
    if low > high {
        return high + 1;
    }

    let mid = low + (high - low) / 2;

    if p_min[mid as usize] >= k {
        find_furthest(mid + 1, high, k, p_min)
    } else {
        find_furthest(low, mid - 1, k, p_min)
    }
}

fn main() {
    let mut buff = String::new();
    io::stdin().read_to_string(&mut buff).unwrap();

    let mut it = buff.split_whitespace();

    let n = read!(it, usize);
    let q = read!(it, usize);

    let h: Vec<u32> = (0..n).map(|_| read!(it, u32)).collect();

    let mut p_min = Vec::with_capacity(n);
    build_prefix(0, n, u32::MAX, &h, &mut p_min);

    for _ in 0..q {
        let t = read!(it, u32);

        match t {
            1 => {
                let j = read!(it, usize);
                println!("{}", p_min[j - 1]);
            }
            2 => {
                let k = read!(it, u32);
                if k > p_min[0] {
                    println!("0");
                } else {
                    let ans = find_furthest(0, (n - 1) as u32, k, &p_min);
                    println!("{}", ans);
                }
            }
            _ => {}
        }
    }
}
