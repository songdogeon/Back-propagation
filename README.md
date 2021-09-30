# Back-propagation
Back-propagation 역전파 c++ 구현

### Updating Weight
y = w*x +b
- x와 bias 값이 고정인경우 weight값을 조정하여 원하는 y 값을 찾는다
- 시그마에서 w에 대해서 미분-> x
- x가 양수 일때 시그마 값증가 , 음수일때 시그마 값 감소

### Updating Bias 
y = w*x +b
- x와 weight 값이 고정인경우 bias값을 조정하여 원하는 y 값을 찾는다
- 시그마에서 b에 대해서 미분-> 1
- 시그마를 증가 시키고 싶다면 b를 증가, 감소시키고 싶다면 b감소

### Updating Affine Sum
f(sigma)=sigma // f(sigma)=y
- linear fuction 이기때문에 시그마값 증가하면 y 값도 증가

## Updating Oupt
- weight or bias 중 좋은 콤비네이션을 찾는게 어려움

### Back-propagation
- 오류 펑션 E = 1/2(y_target-y)^2
- 전으로 거슬러 올라 가면서 적절한 w,b값을 찾음

### The Gradient Descendent Method
- 오류 펑션 E의 최솟값을 구함
- 오류 펑션 E를 w 로 미분하여 오류평션의 기울기를 구함
- 기울기가 0에 가까운 값을 찾는것이 The gradient Descendent 의 목표

### Chain Rule for Weight
- w_updated = w - a * (y - y_target) * 1 * 1 * x //Chain Rule 을 사용하여 w_updated 유도

### Chain Rule for Bias
- b_updated = b - a * (y - y_targer) * 1 * 1 * 1 

### Training with Back-propagation 
while(E is not small enough)
{
    Feed-forward
    Update W and B by back-propagation
}
