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
    let v: Vec<String> = read_vec();
    let a: Vec<char> = v[0].chars().collect();
    let b: Vec<char> = v[1].chars().collect();
    let c: Vec<char> = v[2].chars().collect();

    if a[a.len() - 1] == b[0] && b[b.len() - 1] == c[0] {
        println!("YES");
    } else {
        println!("NO");
    }
}
