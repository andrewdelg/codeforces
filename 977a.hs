main = do
    input <- getLine
    let intedInput = map read (words input) :: [Int]
    let n:k:_ = intedInput
    putStrLn $ show $ (iterate wrongSub n) !! k


wrongSub :: Int -> Int
wrongSub n
    | n `mod` 10 /= 0 = n - 1
    | otherwise   = n `div` 10
