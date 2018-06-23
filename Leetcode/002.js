// 96.15%
var addTwoNumbers = function (l1, l2) {
    if (l1 === null) return l2;
    if (l2 === null) return l1;
    let mod = (l1.val + l2.val) % 10;
    let extra = (l1.val + l2.val) > 9 ? 1 : 0;

    let lsum = new ListNode(mod);
    if (l1.next === null) {
        lsum.next = extra > 0 ? addTwoNumbers(new ListNode(extra), l2.next) : l2.next;
        return lsum;
    }
    if (l2.next === null) {
        lsum.next = extra > 0 ? addTwoNumbers(new ListNode(extra), l1.next) : l1.next;
        return lsum;
    }
    lsum.val = mod;
    let l2withextra = extra > 0 ? addTwoNumbers(new ListNode(extra), l2.next) : l2.next;
    lsum.next = addTwoNumbers(l1.next, l2withextra);
    return lsum;
};

var addTwoNumbers = function (l1, l2) {
    if (l1 === null) return l2;
    if (l2 === null) return l1;
    let mod = (l1.val + l2.val) % 10;
    let extra = (l1.val + l2.val) > 9 ? 1 : 0;

    let lsum = new ListNode(mod);
    lsum.val = mod;
    let l1AddExtra = extra > 0 ? addTwoNumbers(new ListNode(extra), l1.next) : l1.next;
    lsum.next = addTwoNumbers(l1AddExtra, l2.next);
    return lsum;
};

// no recusion
var addTwoNumbers = function (l1, l2) {
    let extra = 0;
    let result = [];
    let n1 = l1;
    let n2 = l2;
    while (n1 || n2 || extra) {
        if (!n1) n1 = { val: 0, next: null };
        if (!n2) n2 = { val: 0, next: null };
        let mod = n1.val + n2.val + extra;
        result.push(mod % 10);
        extra = mod > 9 ? 1 : 0;
        n1 = n1.next;
        n2 = n2.next;
    }
    return result;

};