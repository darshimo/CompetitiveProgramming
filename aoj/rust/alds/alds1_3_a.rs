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
    let sv: Vec<String> = read::read_vec();

    let mut stack: Vec<i32> = Vec::new();

    for s in sv {
        if s == "+" {
            let b = stack.pop().unwrap();
            let a = stack.pop().unwrap();
            stack.push(a + b);
        } else if s == "-" {
            let b = stack.pop().unwrap();
            let a = stack.pop().unwrap();
            stack.push(a - b);
        } else if s == "*" {
            let b = stack.pop().unwrap();
            let a = stack.pop().unwrap();
            stack.push(a * b);
        } else {
            let num: i32 = s.parse().unwrap();
            stack.push(num);
        }
    }

    println!("{}", stack[0]);
}
