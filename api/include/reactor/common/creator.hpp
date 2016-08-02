#ifndef REACTOR_COMMON_CREATOR_HPP
#define REACTOR_COMMON_CREATOR_HPP


#include <memory>


#define CREATE(scope, var, ...) CREATE_##scope(var, __VA_ARGS__)
#define CREATE_PTR(scope, ptrType, ptr, ...) CREATE_PTR_##scope(ptrType, ptr, __VA_ARGS__)
#define CREATE_PTR_STATIC(scope, ptrType, ptr, ...) CREATE_PTR_STATIC_##scope(ptrType, ptr, __VA_ARGS__)
#define CREATE_PTR_DYNAMIC(scope, ptrType, ptr, ...) CREATE_PTR_DYNAMIC_##scope(ptrType, ptr, __VA_ARGS__)


#define INNER_CREATE_STATIC(varType, var, ...) varType var{__VA_ARGS__}

#define INNER_CREATE_DYNAMIC_PROXY(proxyType, varType, var, ...) proxyType var = proxyType(new varType(__VA_ARGS__))

#define INNER_CREATE_PTR_STATIC(ptrType, impType, ptr, ...) \
impType ptr##_imp_tmp_{__VA_ARGS__};\
ptrType ptr = &ptr##_imp_tmp_

#define INNER_CREATE_PTR_DYNAMIC(ptrType, implType, ptr, ...) ptrType ptr = new implType(__VA_ARGS__)

#define INNER_CREATE_PTR_DYNAMIC_SHARED(ptrType, implType, ptr, ...) \
auto ptr##_tmp_ = std::make_shared<implType>(__VA_ARGS__);\
ptrType ptr = ptr##_tmp_.get()


#endif // REACTOR_COMMON_CREATOR_HPP
