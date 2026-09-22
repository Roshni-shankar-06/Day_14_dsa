from threading import Lock


class Foo:
  def __init__(self):
    self.firstDone = Lock()
   
