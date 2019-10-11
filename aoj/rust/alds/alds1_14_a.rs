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
    let t: String = read::read();
    let p: String = read::read();

    let t: Vec<char> = t.chars().collect();
    let p: Vec<char> = p.chars().collect();

    let lt = t.len();
    let lp = p.len();

    for i in 0..lt {
        if i + lp > lt {
            break;
        }
        let mut j: usize = 0;
        while j < lp && t[i + j] == p[j] {
            j += 1;
        }
        if j == lp {
            println!("{}", i);
        }
    }
}
