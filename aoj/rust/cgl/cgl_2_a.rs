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

fn main() {
    let q: u32 = read();

    for _ in 0..q {
        let v: Vec<i32> = read_vec();
        let x1 = v[2] - v[0];
        let y1 = v[3] - v[1];
        let x2 = v[6] - v[4];
        let y2 = v[7] - v[5];
        if x1 * y2 == x2 * y1 {
            println!("2");
        } else if x1 * x2 + y1 * y2 == 0 {
            println!("1");
        } else {
            println!("0");
        }
    }
}
