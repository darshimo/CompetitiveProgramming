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
    let w = v[1];

    let wv: Vec<u32> = read_vec();

    let w0 = wv[0];

    let mut v: Vec<Vec<u32>> = vec![vec![]; 4];

    v[0].push(wv[1]);

    for _ in 1..n {
        let wv: Vec<u32> = read_vec();
        v[(wv[0] - w0) as usize].push(wv[1]);
    }

    let mut l: Vec<usize> = vec![];

    v[0].sort();
    v[0].reverse();
    l.push(v[0].len());
    v[1].sort();
    v[1].reverse();
    l.push(v[1].len());
    v[2].sort();
    v[2].reverse();
    l.push(v[2].len());
    v[3].sort();
    v[3].reverse();
    l.push(v[3].len());

    let mut ans: u32 = 0;

    for l0 in 0..l[0] + 1 {
        for l1 in 0..l[1] + 1 {
            for l2 in 0..l[2] + 1 {
                for l3 in 0..l[3] + 1 {
                    let mut tmp: u32 = 0;
                    let tmpw = w0 * (l0 as u32)
                        + (w0 + 1) * (l1 as u32)
                        + (w0 + 2) * (l2 as u32)
                        + (w0 + 3) * (l3 as u32);
                    for i in 0..l0 {
                        tmp += v[0][i];
                    }
                    for i in 0..l1 {
                        tmp += v[1][i];
                    }
                    for i in 0..l2 {
                        tmp += v[2][i];
                    }
                    for i in 0..l3 {
                        tmp += v[3][i];
                    }
                    if tmpw <= w && tmp > ans {
                        ans = tmp;
                    }
                }
            }
        }
    }
    println!("{}", ans);
}
