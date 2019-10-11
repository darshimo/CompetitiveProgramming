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

fn main() {
    let v: Vec<u32> = read::read_vec();
    let n = v[0];
    let q = v[1];

    let m: Vec<Vec<String>> = read::read_vec2(n);

    let mut queue: VecDeque<(&str, u32)> = VecDeque::new();

    for i in 0..n {
        let name = &m[i as usize][0];
        let time: u32 = m[i as usize][1].parse().unwrap();
        queue.push_back((name, time));
    }

    let mut total: u32 = 0;

    loop {
        let tmp = queue.pop_front();
        if let Some((n, t)) = tmp {
            if t > q {
                total += q;
                queue.push_back((n, t - q));
            } else {
                total += t;
                println!("{} {}", n, total);
            }
        } else {
            break;
        }
    }
}
