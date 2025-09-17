fun main()
{
    val t = readLine() !!.toInt()
                repeat(t)
    {
        val n = readLine() !!.toInt()
                    val array = IntArray(n)
            var same = 0 var diff = 0

            for (i in 0 until n)
        {
            array[i] = readLine() !!.toInt()

                           if (i == 2)
            {
                // Determine which value appears twice among first 3 elements
                val(a, b, c) = Triple(array[0], array[1], array[2])
                    when
                {
                    a == b->
                    {
                        same = a if (c != same) diff = 3
                    }
                    a == c->
                    {
                        same = a if (b != same) diff = 2
                    }
                    b == c->
                    {
                        same = b if (a != same) diff = 1
                    }
                }
            }

            if (i > 2 && array[i] != same)
            {
                diff = i + 1
            }
        }

        println(diff)
    }
}