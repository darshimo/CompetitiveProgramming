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

use std::collections::VecDeque;
use std::fmt::Display;

fn delete(vd: &mut VecDeque<String>, key: &String) {
    let l = vd.len();
    let mut i = 0;
    while i < l {
        if *key == vd[i] {
            break;
        }
        i += 1;
    }
    if i < l {
        vd.remove(i as usize);
    }
}

fn print_vec_deque<T: Display>(a: &VecDeque<T>, n: usize) {
    for i in 0..n {
        print!("{}", a[i]);
        if i == n - 1 {
            println!("");
        } else {
            print!(" ");
        }
    }
}

fn main() {
    let n: u32 = read();
    let commands: Vec<String> = read_col(n);

    let mut vd: VecDeque<String> = VecDeque::new();

    for c in commands {
        if c == "deleteFirst" {
            vd.pop_front();
        } else if c == "deleteLast" {
            vd.pop_back();
        } else {
            let tmp: Vec<String> = c
                .trim()
                .split_whitespace()
                .map(|e| e.parse().ok().unwrap())
                .collect();
            let cmd = &tmp[0];
            let key = &tmp[1];

            if cmd == "insert" {
                vd.push_front(key.clone());
            } else {
                delete(&mut vd, key);
            }
        }
    }

    print_vec_deque(&vd, vd.len() as usize);
}
