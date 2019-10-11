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

fn partition(v: &mut Vec<i32>, p: i32, r: i32) -> i32 {
    let x = v[r as usize];
    let mut i = p - 1;
    for j in p..r {
        if v[j as usize] <= x {
            i += 1;
            let tmp = v[i as usize];
            v[i as usize] = v[j as usize];
            v[j as usize] = tmp
        }
    }
    let tmp = v[(i + 1) as usize];
    v[(i + 1) as usize] = v[r as usize];
    v[r as usize] = tmp;
    i + 1
}
/*
fn quicksort(v: &mut Vec<i32>, p: i32, r: i32) {
    if p < r {
        let q = partition(v, p, r);
        quicksort(v, p, q - 1);
        quicksort(v, q + 1, r);
    }
}
*/
fn search(v: &mut Vec<i32>, p:i32,r:i32,i:i32) -> i32{
    if p<r{
        let q = partition(v, p, r);
        if q == i {
            v[i as usize]
        }else if q>i{
            search(v, p, q-1, i)
        }else{
            search(v, q+1, r, i)
        }
    }else{
        v[p as usize]
    }
}

fn main() {
    let n: i32 = read();
    let m = n / 2;
    let mut d1: Vec<i32> = read_vec();
    let mut d2 = d1.clone();

    let a = search(&mut d1, 0, n-1, m-1);
    let b = search(&mut d2, 0, n-1, m);

    println!("{}", b-a);
}
