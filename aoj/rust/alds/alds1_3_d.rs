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
    let s: String = read::read();

    let cv: Vec<char> = s.chars().collect();

    let mut stack: Vec<u32> = Vec::new();

    let mut r: u32 = 0;

    let mut sum: u32 = 0;

    let mut lakes: Vec<(u32, u32)> = Vec::new();

    for c in cv {
        if c == '\\' {
            stack.push(r);
        } else if c == '/' {
            if let Some(l) = stack.pop() {
                let mut tmp = r - l;
                sum += tmp;
                while !lakes.is_empty() {
                    let (i, w) = lakes.pop().unwrap();
                    if i < l {
                        lakes.push((i, w));
                        break;
                    } else {
                        tmp += w;
                    }
                }
                lakes.push((l, tmp));
            }
        }
        r += 1;
    }

    println!("{}", sum);

    print!("{}", lakes.len());
    for (_, w) in lakes {
        print!(" {}", w);
    }
    println!("");
}
