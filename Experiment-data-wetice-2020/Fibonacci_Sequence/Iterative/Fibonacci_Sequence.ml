
let fib_iter n =
  if n < 2 then
    n
  else let fib_prev = ref 1
  and fib = ref 1 in
    for num = 2 to n - 1 do
      let temp = !fib in
        fib := !fib + !fib_prev;
        fib_prev := temp
    done;
    !fib
    let _ =
      let n =
        try int_of_string Sys.argv.(1)
        with Invalid_argument _ -> 1 in
      Printf.printf " The Fibonacci of %d is %d " n (fib_iter n)