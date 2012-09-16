#    $template_header
#    $args_count
#    $args_sign
#    $args_cast    :    A0 a0 = Type<A0>::Cast(args[0]);
#    $args_list

# Maximum number of arguments
max_args = 9

# Read the template file
f = file("template.cpp")
code = f.read()

# Make the zero parameters version first
version = code
version = version.replace("$template_header", "")
version = version.replace("$comma", "")
version = version.replace("$args_decl", "")
version = version.replace("$args_count", "0")
version = version.replace("$args_sign", "")
version = version.replace("$args_cast", "")
version = version.replace("$args_list", "")

print (version)

arg_cast_templ = "Type<A$num>::GetFunctionTmpl()"

# Make the argument versions
for n in range(1, max_args+1):
    version = code
    args_decl = ""
    args_sign = ""
    args_cast = ""
    args_list = ""
    comma = ", "
    template_header = "template<$args_decl>"
    
    for i in range(0, n):
        if (i > 0):
            args_cast += ", "
            args_decl += ", "
            args_sign += ", "
            args_list += ", "

        args_decl += "typename A" + str(i)
        args_sign += "A" + str(i)
        args_list += "a" + str(i)
        args_cast += arg_cast_templ.replace("$num", str(i))
        
    template_header = template_header.replace("$args_decl", args_decl)
    version = version.replace("$template_header", template_header)
    version = version.replace("$comma", comma)
    version = version.replace("$args_decl", args_decl)
    version = version.replace("$args_count", str(n))
    version = version.replace("$args_sign", args_sign)
    version = version.replace("$args_cast", args_cast)
    version = version.replace("$args_list", args_list)
    print(version)
