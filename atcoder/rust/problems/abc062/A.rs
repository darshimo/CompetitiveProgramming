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
    let v: Vec<u32> = read_vec();
    let x = v[0];
    let y = v[1];
    let g1: Vec<u32> = vec![1, 3, 5, 7, 8, 10, 12];
    let g2: Vec<u32> = vec![4, 6, 9, 11];
    let g3: Vec<u32> = vec![2];
    if g1.contains(&x) && g1.contains(&y)
        || g2.contains(&x) && g2.contains(&y)
        || g3.contains(&x) && g3.contains(&y)
    {
        println!("Yes");
    } else {
        println!("No");
    }
}
