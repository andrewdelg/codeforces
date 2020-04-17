#[allow(unused_imports)]
use std::cmp::{min,max};
#[allow(unused_imports)]
use std::io::{BufWriter, stdin, stdout, Write};
#[allow(unused_imports)]
use std::collections::{ HashMap, VecDeque};
 
#[derive(Default)]
struct Scanner {
    buffer: Vec<String>
}
impl Scanner {
    fn next<T: std::str::FromStr>(&mut self) -> T {
        loop {
            if let Some(token) = self.buffer.pop() {
                return token.parse().ok().expect("Failed parse");
            }
            let mut input = String::new();
            stdin().read_line(&mut input).expect("Failed read");
            self.buffer = input.split_whitespace().rev().map(String::from).collect();
        }
    }
}
 
fn main() {
    let mut scan = Scanner::default();
    let out = &mut BufWriter::new(stdout());
    
    let n = scan.next::<usize>();
    let mut sum: i64 = 0;
    let mut ans: u128 = 0;
    let mut m: HashMap<i64, u128> = HashMap::new();
    let mut rec: Vec<i64> = Vec::new();

    for _ in 0..n {
      let tmp =  scan.next::<i64>();
      sum += tmp;
      rec.push(sum);
    }

    for (j, &val) in rec.iter().enumerate() {
      if j >0 && j < n - 1 {
        if 2*(sum - val) == val {
          let search = val / 2;
          if m.contains_key(&search) {
            ans += *m.get(&search).unwrap();
          } 
        }
      }

      if m.contains_key(&val) {
        m.insert(val, *m.get(&val).unwrap() + 1);
      } else {
        m.insert(val, 1);
      }
    }

    writeln!(out, "{}", ans).ok();

}