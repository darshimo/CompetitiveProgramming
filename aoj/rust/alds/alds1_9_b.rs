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

fn left(i: usize) -> usize {
    (i + 1) * 2 - 1
}

fn right(i: usize) -> usize {
    (i + 1) * 2
}

fn max_heapify(v: &mut Vec<i32>, i: usize) {
    let h = v.len();
    let l = left(i);
    let r = right(i);
    let mut largest = i;

    if l < h && v[l] > v[i] {
        largest = l;
    }
    if r < h && v[r] > v[largest] {
        largest = r;
    }

    if largest != i {
        let tmp = v[largest];
        v[largest] = v[i];
        v[i] = tmp;

        max_heapify(v, largest);
    }
}

fn build_max_heap(v: &mut Vec<i32>) {
    let h = v.len();
    for i in (0..h / 2).rev() {
        max_heapify(v, i);
    }
}

fn main() {
    let h: usize = read::read();
    let mut v: Vec<i32> = read::read_vec();

    build_max_heap(&mut v);

    for i in 0..h {
        print!(" {}", v[i]);
    }
    println!("");
}
