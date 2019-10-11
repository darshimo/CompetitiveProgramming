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
    let v: Vec<u64> = read_vec();
    let n = v[0];
    let k = v[1];
    let ab: Vec<Vec<u64>> = read_vec2(n as u32);

    let mut tbl: Vec<u64> = vec![0; 100000];
    for tmp in ab {
        tbl[(tmp[0] - 1) as usize] += tmp[1];
    }

    let mut cnt: u64 = 0;

    for i in 0..100000 {
        cnt += tbl[i];
        if cnt >= k {
            println!("{}", i + 1);
            break;
        }
    }
}
