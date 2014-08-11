import java.util
import java.util.Scanner

import scala.collection.JavaConversions._;

/**
 * Created by JiangHan on 14-4-10.
 */
object U1001 {

  def main(args: Array[String]) {
    val in = new Scanner(System.in)
    val result = new util.ArrayList[Double]()
    while (in.hasNextDouble) {
      val x = Math.sqrt(in.nextDouble())
      result.add(0, x)
    }
    result.foreach(x => println(x))
  }

}
