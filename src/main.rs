use std::env;

fn main() {
    let args: Vec<_> = env::args().collect();

    if args.len() != 2 {
        println!("USAGE: {} <path-to-file>\n", args[0]);
    }

    println!("=== ELF info for `{}` ===\n", args[1]);

}
