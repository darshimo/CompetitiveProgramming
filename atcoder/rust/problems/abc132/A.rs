fn read<T: std::str::FromStr>() -> T {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).ok();
    s.trim().parse().ok().unwrap()
}

fn main() {
    let s: String = read();
    let cv: Vec<char> = s.chars().collect();

    if cv[0] != cv[1] {
        if (cv[0] == cv[2] && cv[1] == cv[3]) || (cv[0] == cv[3] && cv[1] == cv[2]) {
            println!("Yes");
        } else {
            println!("No");
        }
    } else {
        if cv[1] != cv[2] && cv[2] == cv[3] {
            println!("Yes");
        } else {
            println!("No");
        }
    }
}
