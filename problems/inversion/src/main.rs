use std::io::{self, Read};

macro_rules! read {
    ($it:expr, $t:ty) => {
        $it.next().unwrap().parse::<$t>().unwrap()
    };
}

fn merge(nums: &mut [i32], mid: usize) -> u64 {
    let mut inv = 0;
    let mut temp = Vec::with_capacity(nums.len());

    let (left, right) = nums.split_at(mid);
    let (mut i, mut j) = (0, 0);

    while i < left.len() && j < right.len() {
        if left[i] <= right[j] {
            temp.push(left[i]);
            i += 1;
        } else {
            temp.push(right[j]);
            inv += (left.len() - i) as u64;
            j += 1;
        }
    }

    temp.extend_from_slice(&left[i..]);
    temp.extend_from_slice(&right[j..]);

    nums.copy_from_slice(&temp);
    inv
}

fn count_inv(nums: &mut [i32]) -> u64 {
    let n = nums.len();
    if n <= 1 {
        return 0;
    }

    let mid = n / 2;
    let mut inv = 0;

    inv += count_inv(&mut nums[..mid]);
    inv += count_inv(&mut nums[mid..]);
    inv += merge(nums, mid);

    inv
}

fn main() {
    let mut buff = String::new();
    io::stdin().read_to_string(&mut buff).unwrap();

    let mut it = buff.split_whitespace();

    let n = read!(it, usize);
    let mut nums: Vec<i32> = (0..n).map(|_| read!(it, i32)).collect();

    let count = count_inv(&mut nums);

    println!("{}", count);
}
