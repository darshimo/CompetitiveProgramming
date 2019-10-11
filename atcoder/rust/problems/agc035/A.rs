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

use std::cmp::{max, min};
use std::collections::HashMap;

fn main() {
        let _n: usize = read();
        let av: Vec<u32> = read_vec();
        let mut map: HashMap<u32, u32> = HashMap::new();

        for a in av {
                let count = map.entry(a).or_insert(0);
                *count += 1;
        }

        if map.len() > 3 {
                println!("No");
        } else if map.len() == 1 {
                let mut keys = map.keys();
                if *keys.next().expect("hoge") == 0 {
                        println!("Yes");
                } else {
                        println!("No");
                }
        } else if map.len() == 2 {
                let mut keys = map.keys();
                let tmp1 = keys.next().expect("hoge");
                let tmp2 = keys.next().expect("hoge");
                let key0 = min(tmp1, tmp2);
                let key1 = max(tmp1, tmp2);
                if *key0 != 0 {
                        println!("No");
                } else if map[key0] * 2 != map[key1] {
                        println!("No");
                } else {
                        println!("Yes");
                }
        } else if map.len() == 3 {
                let mut vals = map.values();
                let val1 = vals.next().expect("hoge");
                let val2 = vals.next().expect("hoge");
                let val3 = vals.next().expect("hoge");

                let mut keys = map.keys();
                let key1 = keys.next().expect("hoge");
                let key2 = keys.next().expect("hoge");
                let key3 = keys.next().expect("hoge");
                if val1 != val2 || val2 != val3 {
                        println!("No");
                } else if *key1 ^ *key2 == *key3 {
                        println!("Yes");
                } else {
                        println!("No");
                }
        } else {
                println!("No");
        }
}
