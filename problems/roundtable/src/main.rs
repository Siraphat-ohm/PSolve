use std::io::{self, Read};

macro_rules! read {
    ($it:expr, $t:ty) => {
        $it.next().unwrap().parse::<$t>().unwrap()
    };
}

fn main() {
    let mut buff = String::new();
    io::stdin().read_to_string(&mut buff).unwrap();

    let mut it = buff.split_whitespace();

    let n = read!(it, i32);

    let mut shift_counts = vec![0; n as usize];

    for j in 1..=n {
        let f_j = read!(it, i32);

        let mut shift = (f_j - j) % n;

        if shift < 0 {
            shift += n;
        }

        shift_counts[shift as usize] += 1;
    }

    let max = shift_counts.into_iter().max().unwrap_or(0);

    println!("{}", max);
}
