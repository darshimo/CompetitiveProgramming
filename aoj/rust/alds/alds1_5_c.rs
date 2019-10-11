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

use std::ops::Add;
use std::ops::Sub;

struct Point {
    x: f64,
    y: f64,
}

impl Point {
    fn new(x: f64, y: f64) -> Point {
        Point { x, y }
    }

    fn print(&self) {
        println!("{} {}", self.x, self.y);
    }

    fn rot(&self, theta: f64) -> Point {
        let c = theta.cos();
        let s = theta.sin();
        let x = c * self.x - s * self.y;
        let y = s * self.x + c * self.y;
        Point::new(x, y)
    }
}

impl Clone for Point {
    fn clone(&self) -> Point {
        Point::new(self.x, self.y)
    }
}

impl Add for Point {
    type Output = Point;

    fn add(self, other: Point) -> Point {
        Point::new(self.x + other.x, self.y + other.y)
    }
}

impl Sub for Point {
    type Output = Point;

    fn sub(self, other: Point) -> Point {
        Point::new(self.x - other.x, self.y - other.y)
    }
}

fn koch(n: u32, p1: &Point, p2: &Point) {
    if n == 0 {
        p1.print();
    } else {
        let sx = p1.x * 2.0 / 3.0 + p2.x / 3.0;
        let sy = p1.y * 2.0 / 3.0 + p2.y / 3.0;
        let tx = p1.x / 3.0 + p2.x * 2.0 / 3.0;
        let ty = p1.y / 3.0 + p2.y * 2.0 / 3.0;
        let s = Point::new(sx, sy);
        let t = Point::new(tx, ty);
        let tmp = t.clone() - s.clone();
        let u = s.clone() + tmp.rot(std::f64::consts::PI / 3.0);
        koch(n - 1, &p1, &s);
        koch(n - 1, &s, &u);
        koch(n - 1, &u, &t);
        koch(n - 1, &t, &p2);
    }
}

fn main() {
    let n: u32 = read::read();

    let p1 = Point::new(0.0, 0.0);
    let p2 = Point::new(100.0, 0.0);

    koch(n, &p1, &p2);
    p2.print();
}
