#[allow(unused_imports)]
use std::cmp::{min,max};
use std::io::{BufWriter, stdin, stdout, Write};
use std::collections::{HashMap, HashSet};
 
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
    
    let n = scan.next::<i64>();
    let mut scores: HashMap<String, i64> = HashMap::new();
    let mut records: Vec<(String, i64)> = Vec::new();

    for _ in 0..n {
      let name = scan.next::<String>();
      let score = scan.next::<i64>();

      records.push((name.clone(), score));
      if !scores.contains_key(&name) {
        scores.insert(name.clone(), score);
      } else {
        scores.insert(name.clone(), *scores.get(&name).unwrap() + score);
      }
    }

    let max_val = *scores.values().max().unwrap();
    let mut possible = HashSet::new();

    for (k, v) in scores {
      if v == max_val {
        possible.insert(k.clone());
      }
    }


    scores = HashMap::new();
    for r in records {
      let name = r.0;
      let score = r.1;
      if !scores.contains_key(&name) {
        scores.insert(name.clone(), score);
      } else {
        scores.insert(name.clone(), *scores.get(&name).unwrap() + score);
      }

      if *scores.get(&name).unwrap() >= max_val && possible.contains(&name) {
        writeln!(out, "{}", &name).ok();
        break;
      }
    }

    
}