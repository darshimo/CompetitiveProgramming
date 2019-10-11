fn read<T: std::str::FromStr>() -> T {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).ok();
    s.trim().parse().ok().unwrap()
}

fn read_vec<T: std::str::FromStr>() -> Vec<T> {
    read::<String>()
        .split_whitespace()
        .map(|e| e.parse().ok().unwrap())
        .collect()
}

fn read_vec2<T: std::str::FromStr>(n: usize) -> Vec<Vec<T>> {
    (0..n).map(|_| read_vec()).collect()
}

fn read_col<T: std::str::FromStr>(n: usize) -> Vec<T> {
    (0..n).map(|_| read()).collect()
}

fn main() {
    let n: usize = read();
    let p: Vec<usize> = read_vec();
    let mut cnt: u32 = 0;
    for i in 0..n {
        if p[i] != i + 1 {
            cnt += 1
        }
    }
    if cnt <= 2 {
        println!("YES");
    } else {
        println!("NO");
    }
}
