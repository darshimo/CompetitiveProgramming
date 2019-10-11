fn read<T: std::str::FromStr>() -> T {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).ok();
    s.trim().parse().ok().unwrap()
}

fn main() {
    let o: String = read();
    let e: String = read();

    let mut os = o.chars();
    let mut es = e.chars();

    loop {
        if let Some(l) = os.next() {
            print!("{}", l);
        } else {
            break;
        }

        if let Some(l) = es.next() {
            print!("{}", l);
        } else {
            break;
        }
    }
    println!("");
}
