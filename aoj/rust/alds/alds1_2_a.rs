pub fn read<T: std::str::FromStr>() -> T {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).ok();
    s.trim().parse().ok().unwrap()
}

pub fn read_vec<T: std::str::FromStr>() -> Vec<T> {
    read::<String>()
        .split_whitespace()
        .map(|e| e.parse().ok().unwrap())
        .collect()
}

pub fn read_vec2<T: std::str::FromStr>(n: u32) -> Vec<Vec<T>> {
    (0..n).map(|_| read_vec()).collect()
}

pub fn read_col<T: std::str::FromStr>(n: u32) -> Vec<T> {
    (0..n).map(|_| read()).collect()
}

use std::fmt::Display;

fn print_vec<T: Display>(a: &Vec<T>, n: usize) {
    for i in 0..n {
        print!("{}", a[i]);
        if i == n - 1 {
            println!("");
        } else {
            print!(" ");
        }
    }
}

fn bubble_sort<T: Ord + Copy>(a: &mut Vec<T>, n: usize) -> u32 {
    let mut cnt: u32 = 0;
    let mut flag = true;
    while flag {
        flag = false;
        for j in (1..n).rev() {
            if a[j] < a[j - 1] {
                let tmp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = tmp;
                flag = true;
                cnt += 1;
            }
        }
    }
    cnt
}

fn main() {
    let n: usize = read::read();
    let mut a: Vec<i32> = read::read_vec();

    let c = bubble_sort(&mut a, n);

    print_vec(&a, n);

    println!("{}", c);
}
