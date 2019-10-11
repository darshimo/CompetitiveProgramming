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
    let v: Vec<usize> = read_vec();
    let h = v[0];
    let w = v[1];
    let a: Vec<String> = read_col(h);

    for _ in 0..(w + 2) {
        print!("#");
    }
    println!("");
    for tmp in a {
        print!("#");
        print!("{}", tmp);
        println!("#");
    }
    for _ in 0..(w + 2) {
        print!("#");
    }
    println!("");
}
