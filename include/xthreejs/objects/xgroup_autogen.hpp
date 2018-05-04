#ifndef XTHREE_GROUP_HPP
#define XTHREE_GROUP_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"
#include "xwidgets/xprecompiled_macros.hpp"

#include "xtensor/xtensor.hpp"
#include "xtensor/xadapt.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "../core/xobject3d.hpp"

namespace xthree
{
    //
    // group declaration
    //

    template<class D>
    class xgroup : public xobject3d<D>
    {
    public:

        using base_type = xobject3d<D>;
        using derived_type = D;
        using buffer_type = xt::xtensor<float, 2>;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);



    protected:

        xgroup();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using group = xw::xmaterialize<xgroup>;

    using group_generator = xw::xgenerator<xgroup>;

    //
    // group implementation
    //


    template <class D>
    inline void xgroup<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

    }

    template <class D>
    inline void xgroup<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

    }

    template <class D>
    inline xgroup<D>::xgroup()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xgroup<D>::set_defaults()
    {
        this->_model_name() = "GroupModel";
        this->_view_name() = "";
    }
}

//namespace xw
//{
//    XPRECOMPILE(EXTERN, (xthree::xgroup));
//}
#endif