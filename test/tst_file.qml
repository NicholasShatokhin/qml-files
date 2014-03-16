
import QtTest 1.0
import QtQuick 2.1

import org.jemc.qml.Files 1.0

TestCase {
  id: test
  name: "File"
  
  File { id:grep; fileName:"/usr/bin/grep" }
  File { id:file; fileName:"/tmp/qfile" }
  
  function test_it() {
    compare(grep.fileName, "/usr/bin/grep")
    verify(grep.exists)
    verify(grep.size > 1)
    compare(grep.symLinkTarget,"")
  }
  
  function test_open_close() {
    verify(!file.isOpen())
    verify(file.open(File.ReadWrite))
    verify(file.isOpen())
    file.close()
    verify(!file.isOpen())
  }
  
  function test_write_read_peek() {
    verify(file.open(File.ReadWrite|File.Truncate))
    
    var test_strings = [
      ['test',    4], // Normal latin1 encoded string
      ['xx%00zz', 5], // String with null byte in the center
    ]
    
    for(var i=0; i<test_strings.length; i++) {
      var string     = test_strings[i][0]
      var byteLength = test_strings[i][1]
      
      // Write, then reset
      var bytesWritten = file.write(string)
      compare(bytesWritten, byteLength,        "for string: \"%1\"".arg(string))
      verify(file.reset(),                     "for string: \"%1\"".arg(string))
      
      // Peek
      compare(file.peek(bytesWritten), string, "for string: \"%1\"".arg(string))
      
      // Read, then reset
      compare(file.read(bytesWritten), string, "for string: \"%1\"".arg(string))
      verify(file.reset(),                     "for string: \"%1\"".arg(string))
    }
    
    file.close()
  }
  
  function test_readAll_truncate() {
    verify(file.open(File.ReadWrite|File.Truncate))
    compare(file.readAll(), "")
    compare(file.write("test"), 4)
    verify(file.reset())
    compare(file.readAll(), "test")
    file.close()
    
    verify(file.open(File.ReadWrite|File.Truncate))
    compare(file.readAll(), "")
    file.close()
  }
}
