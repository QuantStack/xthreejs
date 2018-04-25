#ifndef XTHREE_SPHERICAL_HPP
#define XTHREE_SPHERICAL_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"
#include "xwidgets/xprecompiled_macros.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "../base/xthree.hpp"

namespace xthree
{
    //
    // spherical declaration
    //

    template<class D>
    class xspherical : public xthree_widget<D>
    {
    public:

        using base_type = xthree_widget<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);


    protected:

        xspherical();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using spherical = xw::xmaterialize<xspherical>;

    using spherical_generator = xw::xgenerator<xspherical>;

    //
    // spherical implementation
    //

    template <class D>
    inline void xspherical<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

    }

    template <class D>
    inline void xspherical<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

    }

    template <class D>
    inline xspherical<D>::xspherical()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xspherical<D>::set_defaults()
    {
        this->_model_name() = "SphericalModel";
        this->_view_name() = "";
    }
}

//namespace xw
//{
//    XPRECOMPILE(EXTERN, (xthree::xspherical));
//}
#endif