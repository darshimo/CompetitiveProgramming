fn read<T: std::str::FromStr>() -> T {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).ok();
    s.trim().parse().ok().unwrap()
}

fn read_col<T: std::str::FromStr>(n: u32) -> Vec<T> {
    (0..n).map(|_| read()).collect()
}

fn cnt(s:&String)->Vec<u32>{
    let mut ret:Vec<u32> =vec![0;26];
    for c in s.chars(){
        ret[((c as i32) - ('a' as i32)) as usize] += 1;
    }
    ret.clone()
}

use std::cmp::min;

fn solve(v1:&Vec<u32>,v2:&Vec<u32>)->Vec<u32>{
    let mut v:Vec<u32> = vec![];
    for i in 0..26{
        v.push(min(v1[i], v2[i]));
    }
    v.clone()
}

fn prnt(v:&Vec<u32>){
    for i in 0..26{
        for _ in 0..v[i as usize]{
            print!("{}", (i+('a' as u8)) as char);
        }
    }
    println!("");
}

fn main() {
    let n: i32 = read();
    let ss: Vec<String> = read_col(n as u32);
    let mut cvv: Vec<Vec<u32>> = vec![];


    for i in 0..n{
        cvv.push(cnt(&ss[i as usize]));
    }

    let mut min = cvv[0].clone();

    for i in 1..n{
        min = solve(&min,&cvv[i as usize]);
    }

    prnt(&min);
}
