from threading import Lock


class Foo:
  def __init__(self):
    self.firstDone = Lock()
    self.secondDone = Lock()
    self.firstDone.acquire()
    self.secondDone.acquire()

  def first(self, printFirst: 'Callable[[], None]') -> None:
  

