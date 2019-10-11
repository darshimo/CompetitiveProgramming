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
    let v: Vec<u32> = read_vec();
    let n = v[0];
    let m = v[1];
    let ab: Vec<Vec<u32>> = read_vec2(m);
    let mut cnt: Vec<u32> = vec![0; n as usize];

    for a in ab {
        for b in a {
            cnt[(b - 1) as usize] += 1;
        }
    }

    for c in cnt {
        println!("{}", c);
    }
}
