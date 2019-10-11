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
    let nw: Vec<u32> = read::read_vec();
    let n = nw[0];
    let mut w = nw[1] as f64;

    let mut vw: Vec<Vec<f64>> = read::read_vec2(n);

    vw.sort_by(|a, b| (b[0] / b[1]).partial_cmp(&(a[0] / a[1])).unwrap());

    let mut ans: f64 = 0.0;

    for i in 0..(n as usize) {
        if w >= vw[i][1] {
            w -= vw[i][1];
            ans += vw[i][0];
        } else {
            ans += vw[i][0] / vw[i][1] * w;
            w = 0.0;
        }
    }

    println!("{}", ans);
}
