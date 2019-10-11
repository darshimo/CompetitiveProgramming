fn read<T: std::str::FromStr>() -> T {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).ok();
    s.trim().parse().ok().unwrap()
}

fn solve(a: String, b: String) {
    let av: Vec<char> = a.chars().collect();
    let bv: Vec<char> = b.chars().collect();
    let len = av.len();
    let mut cnt: usize = 0;
    for i in 0..len {
        if av[i] > bv[i] {
            println!("GREATER");
            break;
        } else if bv[i] > av[i] {
            println!("LESS");
            break;
        }
        cnt += 1;
    }
    if cnt == len {
        println!("EQUAL");
    }
}

fn main() {
    let a: String = read();
    let b: String = read();

    if a.len() > b.len() {
        println!("GREATER");
    } else if b.len() > a.len() {
        println!("LESS");
    } else {
        solve(a, b);
    }
}
